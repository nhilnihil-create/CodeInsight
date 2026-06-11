#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int s;
    cin >> s;
    map<int, int> memo;
    
    int cur = s;
    do{
        if(memo.count(cur)) break;
        
        memo[cur] = 1;
        if(cur % 2 == 0) cur /= 2;
        else cur = cur*3+1;
    }while(1);

    cout << memo.size()+1 << endl;
    return 0;
}