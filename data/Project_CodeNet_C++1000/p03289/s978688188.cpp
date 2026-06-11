#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;

    if(s[0] == 'A'){
        long long count_C = 0;
        for(long long i = 0; i < s.size(); i++){
            if(i == 0 || i == 1 || i == s.size()-1){
                continue;
            }

            if(s[i] == 'C'){
                count_C++;
            }
        }

        long long count_big = 0;
        if(count_C == 1){
            for(long long i = 0; i < s.size(); i++){
                if(isupper(s[i]) != 0){
                    count_big++;
                }
            }

            if(count_big == 2){
                printf("AC\n");
                
            }
            else{
                printf("WA\n");
            }
        }
        else{
            printf("WA\n");
        }
    }
    else{
        printf("WA\n");
    }
    return 0;
}