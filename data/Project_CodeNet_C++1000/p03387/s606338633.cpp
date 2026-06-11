#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    vector<int>x(3);
    cin >> x[0] >> x[1] >> x[2];
    sort(x.begin(),x.end());
    int a=x[0],b=x[1],c=x[2];
    int ans=0;
    if(a%2==b%2&&b%2==c%2){
        int dif1,dif2;
        dif1=c-a;
        dif2=c-b;
        ans=dif1/2 + dif2/2;
    }
    else {
        if(a%2!=b%2&&a%2!=c%2){
            b++;
            c++;
            int dif1,dif2;
            dif1=c-a;
            dif2=c-b;
            ans=dif1/2 + dif2/2+1;
        }
        else if(a%2!=b%2&&b%2!=c%2){
            a++;
            c++;
            int dif1,dif2;
            dif1=c-a;
            dif2=c-b;
            ans=dif1/2 + dif2/2+1;
        }
        else{
            b++;
            a++;
            int dif1,dif2;
            dif1=c-a;
            dif2=c-b;
            ans=dif1/2 + dif2/2+1;
        }
    }
    cout << ans << endl;
}