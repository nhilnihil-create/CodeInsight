#include<bits/stdc++.h>

int main()
{
    std::string deq;
    std::cin >> deq;
    bool res = true;
    int cnt = 0;
    auto l_itr = deq.begin(), r_itr = (deq.end() - 1);

    while(l_itr - deq.begin() < r_itr - deq.begin()){
        if(*l_itr == *r_itr){
            l_itr++;
            r_itr--;
        }else if(*l_itr == 'x'){
            l_itr++;
            cnt++;
        }else if(*r_itr == 'x'){
            r_itr--;
            cnt++;
        }else{
            res = false;
            break;
        }
    }
    std::cout << (res ? cnt : -1) << std::endl;
}