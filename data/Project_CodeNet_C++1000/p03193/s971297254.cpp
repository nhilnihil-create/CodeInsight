#include <iostream>
using namespace std;

int main()
{
    int i, n, h, w, check=0;
    cin >> n >> h >> w;
    
    int A, B;
    
    for(i=0;i<n;i++)
    {
        cin >> A >> B;
        if(h<=A && w<= B)
        {
            check++;
        }
    }
    cout << check << endl;
}