#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    int n, y; cin >> n >> y;
    int a, b, c;
    y /= 1000;
    for (a=0; a<=n;a++){
        for(b=0; b<=n;b++){
                /*if ((10 * a) + (5*b)+ (n-a-b) < y || b<0||c<0){
                    cout << -1 << " " << -1 << " " << -1 << endl;
                    return 0;
                }*/
          if (n-a-b < 0){
                    b=n+1;
            continue;
                }
                if ((10 * a) + (5*b)+ n-a-b == y){
                    cout << a << " " << b << " " << n-a-b << endl;
                    return 0;
                }
                /*`else if (y + 5 > (10 * a) + (5*b)+n-a-b && (10 * a) + (5*b)+c >= y + 1){
                    b--; c++;
                    continue;
                }
                else if (y + 9 > (10 * a) + (5*b)+n-a-b && (10 * a) + (5*b)+c >= y + 5){
                    a--; b++;
                    continue;
                }
                else if ((10 * a) + (5*b)+ n-a-b >= y + 9){
                    a--; c++;
                    continue;
                }*/
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}