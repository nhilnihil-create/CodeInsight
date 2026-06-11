#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int wa(int n){
    int sum = 0;
    //nがゼロになるまで
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  int count = 0;

  //nが値　a < x , x < b　を満たす必要がある
  for(int i = 1; i <= n; i++){//1以上n以下の整数
    //1回だけではだめ　0になるまでループが必要
    int s = wa(i);
    if(a <= s && s <= b){
        count += i;
    }
  }
  cout << count << endl;

}

