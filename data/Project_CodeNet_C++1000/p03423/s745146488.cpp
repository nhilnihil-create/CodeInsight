#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
bool sortDescByFirst(const pair<int,int>&a, const pair<int,int>&b){
    return a.first>=b.first;
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    while(cin>>n){
        cout<<n/3<<endl;
    }
    return 0;
}
