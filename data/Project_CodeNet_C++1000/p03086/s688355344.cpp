#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    string S;
    cin >> S;
    int tempcount = 0;
    int maxcount = 0;
    for (int i = 0; i < S.length(); i++){
        if(S[i] == 'A' ||
           S[i] == 'T' ||
           S[i] == 'C' ||
           S[i] == 'G'){
               tempcount++;
        }
        else {
            tempcount = 0;
        }
        maxcount = max(maxcount, tempcount);
    }
    cout << maxcount << endl;
    return 0;
}