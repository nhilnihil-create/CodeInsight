#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    set<char> s;
    for(int i = 0; i < N; i++){
        char S;
        cin >> S;
        s.insert(S);
    }
    int n = s.size();
  	if(n == 3) cout << "Three" << endl;
  	else cout << "Four" << endl;
}