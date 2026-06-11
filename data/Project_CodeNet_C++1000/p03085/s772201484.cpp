#include <iostream>

int main(){
    char b, ans;
    std::cin >> b;
    switch(b){
        case 'A':
            ans = 'T';
            break;
        case 'T':
            ans = 'A';
            break;
        case 'C':
            ans = 'G';
            break;
        case 'G':
            ans = 'C';
            break;
    }

    std::cout << ans << std::endl;

    return 0;
}
