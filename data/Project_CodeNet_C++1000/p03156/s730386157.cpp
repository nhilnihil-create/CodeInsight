/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,a=0,b=0,ct1=0,ct2=0,ct3=0;
    cin>>n;
    cin>>a>>b;
    vector<int> p(n);
    for(auto &i: p)
    	cin>>i;
    for(int i=0;i<n;++i)
    {
    	if(p[i]<=a)
    		++ct1;
    	else if(p[i]<=b)
    		++ct2;
    	else
    		++ct3;
    }
    cout<<min({ct1,ct2,ct3})<<endl;
}