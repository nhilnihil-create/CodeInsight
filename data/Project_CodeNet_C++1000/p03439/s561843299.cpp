#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
vector<string> field;
void query(int n) {
  if (field[n]!="") return;
  string s;
  cout<<n<<endl;
  cin>>s;
  if(s=="Vacant") exit(0);
  field[n]=s;
}

int main()
{
  int n;
  cin>>n;
  string s;
  int inf=0,sup=n-1,mid=sup/2;
  field=vector<string>(n,"");

  while(inf!=mid) {
    query(inf);
    query(mid);
    if(field[inf]==field[mid]) {
      if((mid-inf)%2==0) inf = mid;
      else sup=mid;
    } else {
      if((mid-inf)%2==0) sup=mid;
      else inf=mid;
    }
    mid=(inf+sup)/2;
  }
  query(sup);
}