#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        if(a+b==c+d)cout<<"Balanced"<<endl;
        else if(a+b>c+d)cout<<"Left"<<endl;
        else cout<<"Right"<<endl;
    }
    return 0;
}
