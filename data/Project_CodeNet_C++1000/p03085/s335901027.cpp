#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  char b;
  cin>>b;
  switch(b){
    case 'A':
    cout<<'T'<<endl;
    break;

    case 'T':
    cout<<'A'<<endl;
    break;

    case 'G':
    cout<<'C'<<endl;
    break;

    case 'C':
    cout<<'G'<<endl;
    break;
  }
  return 0;
}
