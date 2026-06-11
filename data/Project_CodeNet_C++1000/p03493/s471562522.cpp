#include <iostream>
#include <string>
using namespace std;

int main(){
    string values;
    int count = 0;

    cin >> values;

    for(int i = 0; i < values.size(); i++) {
      count += atoi(values.substr(i, 1).c_str());
    }
    cout << count << endl;
}
