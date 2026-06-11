#include <iostream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,k,m;
    cin >> a >> b >> c >> k;
    m=max(max(a,b),c);
    if (a==m){
        for (int i=0;i<k;i++){
            a*=2;
        }
    }else if (m==b){
        for (int i=0;i<k;i++){
            b*=2;
        }

    }else{
        for (int i=0;i<k;i++){
            c*=2;
        }

    }
    cout << a+b+c << endl;    
}