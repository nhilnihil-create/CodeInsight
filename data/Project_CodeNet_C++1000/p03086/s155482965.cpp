#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int m = 0;
    int l = 0; 
    string n;
    cin >> n;
    n += 'p';
    for(int i = 0; i < n.size(); i++){
        if(n.at(i) == 'A' || n.at(i) == 'C' || n.at(i) == 'G' || n.at(i) == 'T'){
            m = 0;
            for(int j = 0; j + i < n.size(); j++ ){
                if(n.at(i + j) == 'A' || n.at(i + j) == 'C' || n.at(i + j) == 'G' || n.at(i + j) == 'T'){
                    m++;
                    }else{       
                    if(m > l){
                        l = m;
                    }
                    break;
                }
            }
        }
    }cout << l << endl;
}
