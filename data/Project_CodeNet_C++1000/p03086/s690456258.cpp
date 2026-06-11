#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;
    int count_max=0;;
    int i=0;
    while(1){
        int count=0;
        while(1){
            if(S.at(i)=='A'||S.at(i)=='C'||S.at(i)=='G'||S.at(i)=='T'){
                count++;
            }else{
                i++;
                break;
            }  
            i++;
            if(i>=S.size()) break;
            
        }
        count_max=max(count,count_max);
        if(i>=S.size()) break;
    }
    cout << count_max <<endl;
    return 0;
}