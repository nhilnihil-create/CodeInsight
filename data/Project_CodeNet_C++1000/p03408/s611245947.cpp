#include<iostream>
#include<vector>
using namespace std;
int main(){
    int blue,red;
    cin >> blue;
    vector<string> blue_card(blue);
    int i,j;
    for(i=0;i<blue;i++){
        cin >> blue_card.at(i);
    }
    cin >> red;
    vector<string> red_card(red);
    for(i=0;i<red;i++){
        cin >> red_card.at(i);
    }
    int ans = 0;
    for(i=0;i<blue;i++){
        int plus = 0,minus = 0;
        for(j=0;j<blue;j++){
            if(blue_card.at(i) == blue_card.at(j)){
                plus++;
            }
        }
        for(j=0;j<red;j++){
            if(blue_card.at(i) == red_card.at(j)){
                minus++;
            }
        }
        if(ans < plus - minus){
            ans = plus - minus;
        }
    }
    if(ans < 0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}