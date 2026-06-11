#include <iostream>

int task(int n);

int N;
int main(){
    std::cin >> N;
    int num=0;
    for(int i=1;i<=N;i+=2){
        if(task(i) == 8){
            num++;
            //std::cout << i << std::endl;
        }
    }
    std::cout << num << std::endl;
}

int task(int n){
    int cnt = 0;
    for(int u=1;u<=n;u++){
        if(n%u==0){
            ++cnt;
        }
    }
    return cnt;
}
