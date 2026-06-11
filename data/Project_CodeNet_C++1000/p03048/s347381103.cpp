#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  int R,G,B,N; cin >> R >> G >> B >> N;

  int cnt = 0;
  for (int r=0;r<=N/R;r++){
    for (int g=0;g<=N/G;g++){
      int res = N - r*R - g*G;
      if (res<0) break;
      if (res%B==0) cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}