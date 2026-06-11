#include <iostream>
using namespace std;
struct point{
    int x,y,h;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    point p[N];
    for(int i = 0; i < N; ++i){
        cin >> p[i].x >> p[i].y >> p[i].h;
    }

    for(int x = 0; x < 101; ++x){
        for(int y = 0; y < 101; ++y){
            long long upper = 1L<<60;
            bool flag = true;
            long long h = -1;
            for(int i = 0; i < N; ++i){
                if(p[i].h == 0){
                    long long tmp = abs(x - p[i].x) + abs(y - p[i].y);
                    if(tmp < upper){
                        upper = tmp;
                    }
                    if(h != -1 && h - tmp > 0){
                        flag = false;
                        break;
                    }
                } else {
                    long long tmp = p[i].h + abs(x - p[i].x) + abs(y - p[i].y);
                    if(upper < tmp){
                        flag = false;
                        break;
                    } 
                    if(h != -1 && h != tmp){
                        flag = false;
                        break;
                    }
                    h = tmp;
                }
            }
            if(flag){
                cout << x << " " << y << " " << h << '\n';
                return 0;
            }
        }
    }
    return 0;
}