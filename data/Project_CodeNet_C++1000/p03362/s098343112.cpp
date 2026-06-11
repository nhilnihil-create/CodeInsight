#include <bits/stdc++.h>
using namespace std;
#define ll	    long long
#define vi      vector <ll>
#define vii     vector <pair<int,int>>
#define ii      pair<int,int>
#define loop(n)	for(ll i=0;i<n;i++)
#define pb      push_back
const ll mod=1e9+7;
void fast();
bool is_prime(int n){
    if(n==2)
        return true;
    if(n%2==0||n==1)
        return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    vi v;
    for(int i=2;i<=55555;i++){
        if(is_prime(i)&&i%5==1)
            v.pb(i);
    }
    int n;
    cin>>n;
    loop(n)
        cout<<v[i]<<" ";
}
void fast(){
std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
/// 20
/// 15 7 13 15 15 15 15 13 19
/*

*/
