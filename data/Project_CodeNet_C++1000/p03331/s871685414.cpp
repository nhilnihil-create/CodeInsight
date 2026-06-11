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

template<typename First,typename Second> void inputTwoVector(std::vector<First> &first,std::vector<Second>& second){
    int N = first.size();
    for(int i = 0;i < N;i++){
        std::cin >> first[i] >> second[i];
    }
}

int getsum(int N){
    int sum = 0;
    while(N != 0){
        sum += N % 10;
        N /= 10;        
    }
    return sum;
}

void calculate(){
    int N;
    input(N);
    int min = 100000;
    for(int a = 1;a < N;a++){
        int b = N - a;
        min = std::min(min,getsum(a) + getsum(b));
    }
    std::cout << min << '\n';
}

int main(int,char**){
    calculate();    
}


