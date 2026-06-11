#include <iostream>
using namespace std;

#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a % b == 0)
    printf("-1\n");
  else
    printf("%lld\n", (long long)a*(b+1));

  return 0;
}
