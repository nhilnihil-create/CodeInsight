#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
  int rp[100010];
  rp[0]=0;
  rep(i,100001){
    if(IsPrime(i+1)&&IsPrime((i+1+1)/2))rp[i+1]=rp[i]+1;
    else rp[i+1]=rp[i];
  }
  int q;
  cin>>q;
  rep(i,q){
    int l,r;
    cin>>l>>r;
    cout<<rp[r]-rp[l-1]<<endl;
  }
}