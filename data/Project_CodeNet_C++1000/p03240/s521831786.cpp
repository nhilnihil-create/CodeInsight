#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>


using namespace std;

struct point{
    int x,y;
    long h;
}points[100];

long height;

bool check_validity(int x, int y, int p, int n){
    int i,j,len;
    long h,cur_h;
    h = points[p].h + abs(points[p].x - x) + abs(points[p].y - y);
    for(i = 0; i < n; i++){
        cur_h = h - abs(points[i].x - x) - abs(points[i].y - y);
        cur_h = max(cur_h,long(0));
        if(cur_h != points[i].h) return false;
    }
    points[p].h = h;
    return true;
}

int main(){
    int i,j,k,n,x,y,p,break_flag;
    long h;
    while(cin >> n){
        memset(points,-1,sizeof(points));
        break_flag = 0;
        p = -1;
        for(i = 0; i < n; i++){
            cin >> x >> y >> h;
            points[i].x = x;
            points[i].y = y;
            points[i].h = h;
            if(p == -1 && h > 0) p = i;
        }
        for(j = 0; j < 101; j++){
            for(k = 0; k < 101; k++){
                if(check_validity(j,k,p,n)){
                    break_flag = 1;
                    break;
                }
            }
            if(break_flag) break;
        }
        cout << j << " " << k << " " << points[p].h << endl;
    }
    return 0;
}