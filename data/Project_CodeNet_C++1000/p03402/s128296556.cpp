#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    vector<string> grid(100,"");
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if (j<=49) {
                grid[i] += "#";
            }
            else
            {
                grid[i] += ".";
            }
        }
    }
    a--;
    b--;
    int co=0;
    while(a>0){
        grid[(co/25)*2].replace(2*(co%25),1,".");
        co++;
        a--;
    }
    co=0;
    while(b>0){
        grid[(co/25)*2].replace(2*(co%25)+51,1,"#");
        co++;
        b--;
    }

    cout << 100 << " " << 100 << endl;
    for(int i = 0; i < 100; i++)
    {
        cout << grid[i] << endl;
    }
    
}