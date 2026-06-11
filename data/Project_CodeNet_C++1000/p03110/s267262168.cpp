#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    int n,i;
    string s;
    double x,ans=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x >> s;
        if(s=="JPY") ans+=x;
        else ans+=(x*380000);
    }
    cout << fixed << setprecision(5) << ans;
}