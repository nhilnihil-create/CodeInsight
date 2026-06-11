#include <iostream>
#include <string>
using namespace std;

int main(){
    string values;
    int count = 0;

    cin >> values;

    for(int i = 0; i < values.size(); i++) {
      count += stoi(values.substr(i, 1));
    }
    cout << count << endl;
}
