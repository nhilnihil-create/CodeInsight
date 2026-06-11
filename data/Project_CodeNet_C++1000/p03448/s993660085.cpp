#include<iostream>
using namespace std;
int main() {
    int c500, c100, c50, total;
    int ncours = 0;
    cin >> c500 >> c100 >> c50 >> total;
    for (int i = 0; i <= c500; i++)
    {
        for (int a = 0; a <= c100; a++)
        {
            for (int q = 0; q <= c50; q++)
            {
                if (total == i * 500 + a * 100 + q * 50)
                    ncours++;
            }
        }
    }
    cout << ncours << endl;
}