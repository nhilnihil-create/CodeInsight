#include <iostream>
#include <string>

int main(){
    std::string S, ans;
    std::cin >> S;

    std::string mon = S.substr(5, 2);
    
    if(mon == "01" || mon == "02" || mon == "03" || mon == "04"){
        ans = "Heisei";
    }
    else{
        ans = "TBD";
    }

    std::cout << ans << std::endl;
    return 0;
}
