#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
    int A, B, K;
    cin >> A >> B >> K;
    stack<int> num;
    for(int i=1;i<101;i++){
      if(A%i==0 && B%i==0){
        num.push(i);
      }
    }

    int ans = 0; 
    rep(i,K-1){
        num.pop();
    }
    printl(num.top());
}
