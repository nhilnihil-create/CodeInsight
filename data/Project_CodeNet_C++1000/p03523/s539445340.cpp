#include<iostream>
#include<string>

bool is_akihabara(std::string s){
    bool check = false;

    if(s == "AKIHABARA") check = true;

    else if (s == "KIHABARA") check = true;
    else if (s == "AKIHBARA") check = true;
    else if (s == "AKIHABRA") check = true;
    else if (s == "AKIHABAR") check = true;

    else if (s == "KIHBARA") check = true;
    else if (s == "KIHABRA") check = true;
    else if (s == "KIHABAR") check = true;
    else if (s == "AKIHBRA") check = true;
    else if (s == "AKIHBAR") check = true;
    else if (s == "AKIHABR") check = true;

    else if (s == "KIHBRA") check = true;
    else if (s == "KIHBAR") check = true;
    else if (s == "KIHABR") check = true;
    else if (s == "AKIHBR") check = true;
    
    else if (s == "KIHBR") check = true;

    return check;
}

int main(void){
    std::string s;
    std::cin >> s;

    if(is_akihabara(s)){
        std::cout << "YES" << std::endl;
        return 0;
    }
    else{
        std::cout << "NO" << std::endl;
        return 0;
    }
}