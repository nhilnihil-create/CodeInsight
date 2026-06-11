#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){
    long long n;
    cin >> n;
    set<string> T;

    string pre_word;

    for(long long i = 0; i < n; i++){
        string word;
        cin >> word;
        if(i == 0){
            T.insert(word);
            pre_word = word;
            continue;
        }

        if(T.find(word) != T.end()){
            printf("No\n");
            return 0;
        }
        else{
            if(word[0] != pre_word[pre_word.size()-1]){
                printf("No\n");
                return 0;
            }
            else{
                T.insert(word);
                pre_word = word;
            }
        }
    }

    printf("Yes\n");
    return 0;
}