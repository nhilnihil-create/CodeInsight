#include<iostream>
#include<set>
using namespace std;

int main(){
    //input
    int N;
    cin >> N;
    set<int> dan;
    int d,i;
    for(i=1; i<=N; i++){
        cin >> d;
        dan.insert(d);
    }

    //output
    cout << dan.size() << endl;
    system("pause");
    return 0;
}