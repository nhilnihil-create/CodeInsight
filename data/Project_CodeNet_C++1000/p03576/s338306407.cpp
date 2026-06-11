#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, k, x[50], y[59];
  vector<long long> X, Y;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
    X.push_back(x[i]);
    Y.push_back(y[i]);
  };
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  unsigned long long mn=(2e9)*(2e9);
  for(int xn=0; xn<n;xn++){
    for(int xx=xn+1;xx<n;xx++){
      for(int yn=0;yn<n;yn++){
        for(int yx=yn+1;yx<n;yx++){
          int cnt=0;
          for(int i=0;i<n;i++){
            if(X[xn]<=x[i]&&x[i]<=X[xx]&&Y[yn]<=y[i]&&y[i]<=Y[yx])cnt++;
          }
          long long square=(X[xx]-X[xn])*(Y[yx]-Y[yn]);
          if(cnt>=k && mn>square){
            mn = square;
            // cout << mn << ' ';
            // cout << X[xn] << ' ' << X[xx] << ' ';
            // cout << Y[yn] << ' ' << Y[yx] << endl;
          }
        }
      }
    }
  }
  cout << mn << endl;
}

