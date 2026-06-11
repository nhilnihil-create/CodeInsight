#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int Max_n = 54;
long long a[Max_n], ans_arr[2* Max_n][2], ans=0;
vector<pair<int, int> > pairs(Max_n);
    
int main(){
    int N;
    cin >> N;

    //if(a[i-1] <= a[i]) //次に進む
    //if(min < a[i]) //もう一度最小値をたす
    //if(a[i-1] > a[i]) //最小値ををたす a[i] + min
    long long min = 10000000;
    int min_idx;
    long long max = -10000000;
    int max_idx;

    for(int i =0; i < N; i++){
        cin >> a[i];
        if(a[i] > max){
            max = a[i];
            max_idx = i;
        }
        if(a[i] < min){
            min = a[i];
            min_idx = i;
        }
    }
    

    if(abs(max) < abs(min)){
        for(int i =N-1; i > 0; i--){
            if(a[i-1] > a[i]){
                a[i-1] += min;
                ans_arr[ans][0] = i -1;
                ans_arr[ans][1] = min_idx;
                ans++;

                if(min > a[i-1]){
                    min = a[i-1];
                    min_idx = i -1;
                }

                if(a[i-1] > a[i]){
                    a[i-1] += min;
                    ans_arr[ans][0] = i - 1;
                    ans_arr[ans][1] = min_idx;
                    ans++;
                }

                if(min > a[i-1]){
                    min = a[i-1];
                    min_idx = i -1;
                }
            }
        }
    }
    else{
        for(int i =1; i < N; i++){
            if(a[i-1] > a[i]){
                a[i] += max;
               

                ans_arr[ans][0] = i;
                ans_arr[ans][1] = max_idx;
                ans++;
                

                if(max < a[i]){
                    max = a[i];
                    max_idx = i;
                }

                if(a[i-1] > a[i]){
                    a[i] += max;

                    ans_arr[ans][0] = i;
                    ans_arr[ans][1] = max_idx;
                    ans++;
                    }

                if(max < a[i]){
                    max = a[i];
                    max_idx = i;
                }
            }
        }

    }
    cout << ans << endl;
    for(int i =0; i < ans; i++){
        cout << ans_arr[i][1] + 1<< " " << ans_arr[i][0] +1  << endl;
    }
    
   

    return 0;
}