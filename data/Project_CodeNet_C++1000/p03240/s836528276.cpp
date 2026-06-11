#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
  	cin >> N;
    int x[N], y[N], h[N];
  	int x0, y0, h0;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> h[i];
      	if(h[i]>=1){
          x0 = x[i];
          y0 = y[i];
          h0 = h[i];
        }
    }
    int ansX=0, ansY=0, ansH=0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            int H = h0+abs(x0-i)+abs(y0-j);
            bool flag = true;
            for (int k = 0; k < N; k++)
            {
                int ash = max(H-abs(x[k]-i)-abs(y[k]-j), 0);
                if(h[k]!=ash) flag = false;
            }
            if(flag){
                    ansX = i;
                    ansY = j;
                    ansH = H;
             }
        }
        
    }
    
    cout << ansX << " " << ansY << " "  << ansH << endl;
}