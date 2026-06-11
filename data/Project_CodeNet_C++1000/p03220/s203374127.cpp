
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]
int gcd(int x, int y)
{
    if(y==0)
        return x;
    return gcd(y, x%y);
}

 long long numbers[500005];

//int a[100005];

 int main(){

 long long n;
cin>>n;

 double t,a;
 cin>>t>>a;

  double mini = INT_MAX;
  int pos=0;

 for(int i=0;i<n;i++){

   double H;
   cin>>H;

    double  x = t-H*0.006;
     double diff ;

  diff = abs(x-a);

   if(diff < mini){
        mini = diff;
     pos = i; }

 }

 cout<<pos+1<<endl;


 return 0;
 }
