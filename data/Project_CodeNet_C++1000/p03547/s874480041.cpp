#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char x,y;
    while(cin>>x>>y){
        if(x<y)cout<<"<"<<endl;
        else if(x>y)cout<<">"<<endl;
        else cout<<"="<<endl;
    }
    return 0;
}
