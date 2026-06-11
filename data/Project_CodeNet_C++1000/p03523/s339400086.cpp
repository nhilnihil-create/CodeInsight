#include<iostream>
#include<string>

bool check(std::string s){
    if(s == "AKIHABARA") return true;
    
    if(s == "AKIHABAR") return true;
    if(s == "AKIHABRA") return true;
    if(s == "AKIHBARA") return true;
    if(s == "KIHABARA") return true;

    if(s == "AKIHABR") return true;
    if(s == "AKIHBAR") return true;
    if(s == "KIHABAR") return true;
    if(s == "AKIHBRA") return true;
    if(s == "KIHABRA") return true;
    if(s == "KIHBARA") return true;

    if(s == "KIHBRA") return true;
    if(s == "KIHBAR") return true;
    if(s == "KIHABR") return true;
    if(s == "AKIHBR") return true;

    if(s == "KIHBR") return true;

    return false;
}

int main(void){
    std::string s;
    std::cin >> s;

    bool flag = check(s);
    if(flag){
        std::cout << "YES" << std::endl;
        return 0;
    }
    else{
        std::cout << "NO" << std::endl;
        return 0;
    }
}