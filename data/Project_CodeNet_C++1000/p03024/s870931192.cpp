#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    cin >> line;
    
    int o = 0;
    
    for(int i = 0; i < line.size(); i++){
       if(line.at(i) == 'o'){
           o++;
       } 
    }
    
    if(((15 - line.size()) >= (8-o))){
    cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
