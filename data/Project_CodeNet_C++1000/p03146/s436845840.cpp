#include <set>
#include <iostream>
using namespace std;

int s, idx=1, prevA;
set<int> a;

int main(){
    cin >> s;
    prevA = s;
    a.insert(s);
    while(true){
        idx++;
        prevA%2==0? prevA/=2: prevA=prevA*3+1;
        a.insert(prevA);
        if(a.size() != idx){
            break;
        }
    }
    cout << idx << endl;
}
