#include<bits/stdc++.h>

#define loop(n) for(int i = 0;i < (int)(n);++i)
#define rep(i,n) for(int i = 0;i < (int)(n);++i)
#define all(vec) (vec).begin(),(vec).end()
#define sort(vec) std::sort(all(vec))
#define rev(vec) std::reverse(all(vec))

void input(){return;}
template<typename First,typename... Rest> void input(First &first,Rest&... rest){
    std::cin >> first;
    input(rest...);
}

void inputVector(){return;}
template<typename First,typename... Rest> void inputVector(std::vector<First> &first,Rest&... rest){
    int N = first.size();
    for(int i = 0;i < N;i++){
        std::cin >> first[i];
    }
    inputVector(rest...);
}


void calculate(){

}

int main(int,char**){
    int A,B,C,Sum;
    int res = 0;
    input(A,B,C,Sum);
    rep(a,A + 1){
        rep(b,B + 1){
            rep(c,C + 1){
                int sum = 500 * a + 100 * b + 50 * c;
                if(sum == Sum) res++; 
            }
        }
    }
    std::cout << res << '\n';
}


