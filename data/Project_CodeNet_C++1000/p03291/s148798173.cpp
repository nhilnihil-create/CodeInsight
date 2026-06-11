#include<bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;

//繰り返し二乗法
int64_t pown(int64_t x, int64_t n) {
  int64_t ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans = ans * x;
      ans %= MOD;
    }
    x = x * x;//一周する度にx, x^2, x^4, x^8となる
    x %= MOD;
    n >>= 1; //桁をずらす n = n >> 1
  }
  return ans;
}

int64_t calc(int64_t A,int64_t C, int64_t QB, int64_t QA){
    int64_t x = A*C*pown(3,QB+QA); //AC
    x %= MOD;
    x += A*QA*pown(3,QB+QA-1); //A?
    x %= MOD;
    x += QB*C*pown(3,QB+QA-1); //?C
    x %= MOD;
    x += QB*QA*pown(3,QB+QA-2);  //??
    x %= MOD;
    return x;
}

int main() {

    // input from txt （提出時にこの箇所は削除すること）
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;
    cin >> S;
    int64_t a = 0;
    int64_t sum_b = 0;
    int64_t ans = 0;
    int64_t Q_before = 0;
    int64_t Q_after = 0;
    int64_t C = 0;

    
    for(int i=0; i<S.size(); i++){
        if(S.at(i) == '?'){
            Q_after++;
        }
        if(S.at(i) == 'C'){
            C++;
        }
    }
    

    
    for(int i=0; i<S.size(); i++){
        if(S.at(i) == 'A'){
            a++;
        }
        else if(S.at(i) == 'B'){
            ans += calc(a,C,Q_before,Q_after);
            ans %= MOD;
        }
        else if(S.at(i) == 'C'){
            C--;
        }
        else{
            Q_after--;
            ans += calc(a,C,Q_before,Q_after);
            ans %= MOD;
            Q_before++;
        }
    }
    
    cout << ans << endl;
    
}
