#include <iostream>
using namespace std;

int main() {
    int array_num;
    cin >> array_num;
    long array[array_num];
    long abs_max = 0;
    long abs_max_index = 0;
    long sign;
    for(int i = 0; i < array_num ; i++)
    {
        cin >> array[i];
        if(abs(array[i]) > abs_max)
        {
            abs_max = abs(array[i]);
            abs_max_index = i;
            sign = array[i] / abs(array[i]);
        }
    }

    cout << 2*array_num << endl;            
    for(int i = 0; i < array_num ; i++)
    {
        {
            cout << abs_max_index+1 << " " << i+1 << endl;
        }
    }

    if(sign > 0)
    {
        cout << 1 << " " << 1 << endl;            
        for(int i = 0; i < array_num  - 1; i++)
        {
            cout << i+1 << " " << i+2 << endl;            
        }
    }
    if(sign < 0)
    {
        cout << array_num << " " << array_num << endl;            
        for(int i = array_num; i > 1; i--)
        {
            cout << i << " " << i-1 << endl;            
        }
    }
}
