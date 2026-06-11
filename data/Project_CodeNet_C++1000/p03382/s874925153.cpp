#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
#define PI 3.14159265358979323846
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

int n;
vi in;

int main(){
  scanf("%d", &n);
  in.resize(n);
  for(int& e : in) scanf("%d", &e);

  sort(all(in));

  int a = in.back(), b = in[0];

  int m1 = (a + 1) / 2, m2 = m1;
  if(a % 2 == 0) ++m2;

  for(int i = 1;i + 1 < n;++i){
    int d1 = min(abs(m1 - b), abs(m2 - b));
    int d2 = min(abs(m1 - in[i]), abs(m2 - in[i]));
    if(d2 < d1) b = in[i];
  }

  printf("%d %d\n", a, b);

  return 0;
}
