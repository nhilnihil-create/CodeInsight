#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int N = s.size();
    long long rsl = 0;
    vector<int>w,b;
    for(int i=0; i<N; i++){
        if(s[i]=='B'){
            b.push_back(i);
        }else{
            w.push_back(i);
        }
    }
    for(int i=0; i<w.size(); i++){
        rsl += w[i] - i;
    }
    cout << rsl << endl;
    return 0;
}