#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;
    if(s == "AKIHABARA" ||
       s == "AKIHABAR" ||
       s == "AKIHABRA" ||
       s == "AKIHBARA" ||
       s == "KIHABARA" ||
       s == "AKIHABR" ||
       s == "AKIHBAR" ||
       s == "KIHABAR" ||
       s == "AKIHBRA" ||
       s == "KIHABRA" ||
       s == "KIHBARA" ||
       s == "AKIHBR" ||
       s == "KIHABR" ||
       s == "KIHBAR" ||
       s == "KIHBRA" ||
       s == "KIHBR" ){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}