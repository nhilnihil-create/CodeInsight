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
    int N;
    input(N);
    rep(i,26){
        rep(j,15){
            int sum = 4 * i + 7 * j;
            if(sum == N){
                std::cout << "Yes\n";
                return;
            }
        }
    }
    std::cout << "No\n";
}

int main(int,char**){
    calculate();    
}


