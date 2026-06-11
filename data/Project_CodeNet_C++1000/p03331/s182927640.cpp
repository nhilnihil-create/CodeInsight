//WA 7
#include <bits/stdc++.h>
 
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ii pair<int,int>
#define qu queue <int>
#define qmax priority_queue <int>
#define qmin priority_queue <int, vector<int>,greater<int>>

using namespace std;

int solve(int n){
    int ans =0;

    do{
        ans += (n%10);
        n /=10;
    }while(n);

    return ans == 1 ? 10 : ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    auto ans = solve(n);

    cout<<ans<<endl;

    return 0;
}