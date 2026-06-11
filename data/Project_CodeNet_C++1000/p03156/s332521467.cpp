#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int N,A,B;
    cin >> N >> A >> B;
    int first=0,second=0,third=0;
    for(int i=0;i<N;i++){
        int P;
        cin >> P;
        if(P <= A)first++;
        else if(P > A && P <= B)second++;
        else if(P > B)third++;
    }
    
    cout << min(first,min(second,third));
    
}
