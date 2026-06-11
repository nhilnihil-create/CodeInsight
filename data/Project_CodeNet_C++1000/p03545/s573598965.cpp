#include <iostream>
#include <bitset>
#include <cctype>
using namespace std;

string ABCD;
string ans;

void bitSearch(){
    
    for(int i = 0; i < (1 << 3); i++){
        
        bitset<3> bit(i);
        
        int sum = ABCD[0] - '0';
        ans = ABCD[0];
        
        for(int j = 0; j < 3; j++){
            if( bit.test(j) ){
                sum += ABCD[j+1] - '0';
                ans += "+";
                ans += ABCD[j+1];
            }
            else{
                sum -= ABCD[j+1] - '0';
                ans += "-";
                ans += ABCD[j+1];
            }
        }
        
        if(sum == 7){
            cout << ans << "=7" << endl;
            return;
        }
        
    }
    return;
    
}



int main(void){
    
    cin >> ABCD;
    
    bitSearch();
    
    return 0;
    
}
