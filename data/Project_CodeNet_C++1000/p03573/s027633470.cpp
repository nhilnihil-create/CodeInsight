    #include <iostream>

    using namespace std;

    int main()
    {
        int num1, num2, num3;
        cin >> num1 >> num2 >> num3;
        if (num1 == num2)
            cout << num3;
        else if (num1 == num3)
            cout << num2;
        else
            cout << num1;
        return 0;
    }
