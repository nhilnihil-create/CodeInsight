#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<vector<int>> c(3,vector<int>(3));

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> c.at(i).at(j);
        }
    }

    bool ans = false;

    for(int a1=0; a1<=c.at(0).at(0); a1++){
        for(int a2=0; a2<=c.at(1).at(1); a2++){
            for(int a3=0; a3<=c.at(2).at(2); a3++){
    
            int b1 = c.at(0).at(0) - a1;
            int b2 = c.at(1).at(1) - a2;
            int b3 = c.at(2).at(2) - a3;

        
            if(c.at(0).at(1) != a1+b2)
                continue;
            if(c.at(0).at(2) != a1+b3)
                continue;
            if(c.at(1).at(0) != a2+b1)
                continue;
            if(c.at(1).at(2) != a2+b3)
                continue;
            if(c.at(2).at(0) != a3+b1)
                continue;
            if(c.at(2).at(1) != a3+b2)
                continue;
            
            ans = true;
            break;
            }
        }
    }

    if(ans)
    cout << "Yes" <<endl;
    else
    cout << "No" << endl;
    
}