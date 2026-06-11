# include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, a[N];

int main(){
      scanf("%d", &n);

      for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
      }

      sort(a + 1, a + n + 1);

      cout << a[n] << " ";

      int mx = 2e9, ind = 0;

      for(int i = 1; i < n; i ++){
            if(mx > abs(a[i] - (a[n] / 2))){
                  mx = abs(a[i] - (a[n] / 2));
                  ind = i;
            }
            if(mx > abs(a[i] - ((a[n] + 1) / 2))){
                  mx = abs(a[i] - ((a[n] + 1) / 2));
                  ind = i;
            }
      }

      cout << a[ind] << endl;
}
