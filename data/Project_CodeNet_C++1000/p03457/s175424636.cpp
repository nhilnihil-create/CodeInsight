#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int t, x, y; cin >> t >> x >> y;
    if(x+y>t){
        cout << "No" << endl;
        return 0;
    }
    bool flg = 0;
    for(int i=0; i<n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a-t>=abs(x-b)+abs(y-c)&&(a-t)%2==(abs(x-b)+abs(y-c))%2){
        }else{
            flg = 1;
        }
        t=a; x=b; y=c;
    }
    if(flg) puts("No");
    else puts("Yes");
    return 0;
}