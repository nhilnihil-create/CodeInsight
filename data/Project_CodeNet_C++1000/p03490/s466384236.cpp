#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int x_pos[16010][16010] = {0};
int y_pos[16010][16010] = {0};
int x_dir[8000] = {};
int y_dir[8000] = {};

int main()
{
    string s;
    int x, y;
    cin >> s;
    scanf("%d %d", &x, &y);
    int direction = 0;
    int x_res;
    int y_res;
    int x_idx = 0;
    int y_idx = 0;
    int val = 0;
    int count = 0;
    int x_sum = 0;
    int y_sum = 0;
    int first_count = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'F'){
            first_count ++;
        }
        else{
            break;
        }
    }

    for(int i=first_count; i<=s.size(); i++){
        if(s[i] == 'F'){
            if(val == 0){
                direction = direction ^ (count % 2);
                count = 0;
            }
            val++;
        }
        else{
            if(val != 0){
                if(direction == 0){
                    x_dir[x_idx] = val;
                    x_sum -= val;
                    x_idx++;
                }
                else{
                    y_dir[y_idx] = val;
                    y_sum -= val;
                    y_idx++;
                }
                val = 0;
            }
            count++;
        }
    }

    x_res = x - x_sum - first_count;
    y_res = y - y_sum;

    if(x_res < 0 || y_res < 0){
        printf("No\n");
    }
    else{
        x_pos[0][0] = 1;
        y_pos[0][0] = 1;

        for(int i=0; i<x_idx; ++i){
            for(int j=0; j<=x_res; ++j){
                x_pos[i+1][j] |= x_pos[i][j];
                if(j>=x_dir[i]*2){
                    x_pos[i+1][j] |= x_pos[i][j - x_dir[i]*2];
                }
            }
        }

        for(int i=0; i<y_idx; ++i){
            for(int j=0; j<=y_res; ++j){
                y_pos[i+1][j] |= y_pos[i][j];
                if(j>=y_dir[i]*2){
                    y_pos[i+1][j] |= y_pos[i][j - y_dir[i]*2];
                }
            }
        }

        if(x_pos[x_idx][x_res] == 1 && y_pos[y_idx][y_res] == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}
