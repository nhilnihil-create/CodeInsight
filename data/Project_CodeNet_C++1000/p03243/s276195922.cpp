#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;

vector<int>v;
vector<int>ans;
int res;
int sumOfDigits (int n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}


ll fastpow(ll a,ll b){
if(!b)
    return 1;

ll  sq=fastpow(a,b/2);
sq*=sq;
if(b%2!=0)
    sq*=a;

    return sq;

}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

const int maxx=1e3+100;
int c[maxx];
int n,m,d;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;

vector<int>v;

for(int i=1;i<=9;i++)
    v.push_back(i*111);

  for(auto s:v){
    if(n<=s)
    {
        cout<<s<<"\n";
        break;
    }
  }




	return 0;
}





